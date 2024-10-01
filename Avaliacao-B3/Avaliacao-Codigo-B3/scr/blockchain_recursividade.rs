extern crate sha2;
use sha2::{Digest, Sha256};
use std::time::{SystemTime, UNIX_EPOCH};

// Estrutura de um bloco da blockchain
struct Block {
    index: u64,
    timestamp: u128,
    data: String,
    previous_hash: String,
    hash: String,
    nonce: u64,
    next: Option<Box<Block>>, // Apontador para o próximo bloco
}

// Estrutura da Blockchain como uma lista ligada
struct Blockchain {
    head: Option<Box<Block>>, // Primeira referência na lista ligada
    difficulty: usize,
}

impl Blockchain {
    // Cria uma nova blockchain com o bloco gênesis
    fn new(difficulty: usize) -> Self {
        let mut genesis_block = Blockchain::create_genesis_block();
        genesis_block.hash = Blockchain::calculate_hash(&genesis_block); // Calcula o hash do bloco gênesis
        
        Blockchain {
            head: Some(Box::new(genesis_block)),
            difficulty,
        }
    }

    // Cria o bloco gênesis
    fn create_genesis_block() -> Block {
        Block {
            index: 0,
            timestamp: Blockchain::current_timestamp(),
            data: "Genesis Block".to_string(),
            previous_hash: String::from("0"),
            hash: String::new(),
            nonce: 0,
            next: None,
        }
    }

    // Obtém o timestamp atual
    fn current_timestamp() -> u128 {
        let start = SystemTime::now();
        start.duration_since(UNIX_EPOCH).unwrap().as_millis()
    }

    // Minera um novo bloco
    fn mine_block(&mut self, data: String) {
        // Encontra o último bloco na lista
        let mut current = &mut self.head;
        while let Some(ref mut block) = current {
            if block.next.is_none() {
                // Achou o último bloco, podemos criar o novo bloco aqui
                let previous_hash = block.hash.clone();
                let mut new_block = Block {
                    index: block.index + 1,
                    timestamp: Blockchain::current_timestamp(),
                    data,
                    previous_hash,
                    hash: String::new(),
                    nonce: 0,
                    next: None,
                };

                // Mineração do bloco com prova de trabalho
                while !Blockchain::is_valid_hash(&new_block.hash, self.difficulty) {
                    new_block.nonce += 1;
                    new_block.hash = Blockchain::calculate_hash(&new_block);
                }

                println!("Bloco minerado com sucesso! Nonce: {}", new_block.nonce);

                // Insere o novo bloco no final da lista
                block.next = Some(Box::new(new_block));
                break;
            }
            current = &mut block.next;
        }
    }

    // Calcula o hash de um bloco
    fn calculate_hash(block: &Block) -> String {
        let block_data = format!(
            "{}{}{}{}{}",
            block.index, block.timestamp, block.data, block.previous_hash, block.nonce
        );
        let mut hasher = Sha256::new();
        hasher.update(block_data);
        format!("{:x}", hasher.finalize())
    }

    // Verifica se o hash é válido de acordo com a dificuldade
    fn is_valid_hash(hash: &str, difficulty: usize) -> bool {
        hash.starts_with(&"0".repeat(difficulty))
    }

    // Exibe todos os blocos na blockchain
    fn display(&self) {
        let mut current = &self.head;
        while let Some(ref block) = current {
            println!(
                "Index: {}, Timestamp: {}, Data: {}, Hash Anterior: {}, Hash Atual: {}",
                block.index, block.timestamp, block.data, block.previous_hash, block.hash
            );
            current = &block.next;
        }
    }

    // Valida a blockchain recursivamente
    fn validate_chain_recursively(&self) -> bool {
        if let Some(ref block) = self.head {
            return Blockchain::validate_block_recursively(block);
        }
        true
    }

    // Valida cada bloco com o anterior usando recursão
    fn validate_block_recursively(block: &Block) -> bool {
        if let Some(ref next_block) = block.next {
            if block.hash != next_block.previous_hash {
                return false;
            }
            if next_block.hash != Blockchain::calculate_hash(next_block) {
                return false;
            }
            return Blockchain::validate_block_recursively(next_block);
        }
        true
    }
}

pub(crate) fn main() {
    println!("\n\nBlockchain com recursão:\n");

    // Criação da blockchain com dificuldade 4 (mínimo de 4 zeros no hash)
    let mut blockchain = Blockchain::new(4);

    // Minera alguns blocos
    for i in 1..=3 {
        blockchain.mine_block(format!("Transação {}", i));
    }

    // Exibe todos os blocos da blockchain
    blockchain.display();

    // Valida a blockchain
    if blockchain.validate_chain_recursively() {
        println!("Blockchain é válida!");
    } else {
        println!("Blockchain é inválida!");
    }
}
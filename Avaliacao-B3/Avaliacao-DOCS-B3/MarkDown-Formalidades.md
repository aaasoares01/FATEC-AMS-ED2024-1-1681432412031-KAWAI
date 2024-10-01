## Projeto Simulação de Blockchain

**Identificação dos componentes da equipe:**

- Pedro Nascimento
- Matheus Macedo 
- Kawai Soares
- Thiago Ulloa
- Guilherme Pradela

---

## Descrição de Negócio

O objetivo deste projeto é criar uma simulação de uma blockchain utilizando a linguagem Rust, com foco nos princípios fundamentais de uma blockchain, como segurança, imutabilidade e descentralização. Este projeto simula um processo de mineração, geração de hashes e validação de blocos. A blockchain resultante é uma cadeia de blocos que contém transações fictícias, sendo minerados por meio de um algoritmo de "prova de trabalho".

### Problema a ser resolvido

A blockchain busca resolver questões de segurança e confiança ao armazenar dados de forma descentralizada. Em um sistema tradicional, os dados podem ser manipulados ou perdidos, mas com uma blockchain:

- **Segurança**: Os dados são protegidos por criptografia.
- **Imutabilidade**: Após inseridos, os dados não podem ser modificados sem invalidar os blocos subsequentes.
- **Descentralização**: Os dados podem ser verificados sem depender de uma entidade central.

### Objetivo

O objetivo é criar um sistema de blockchain funcional que realiza as seguintes tarefas:

1. Mineração de blocos, onde um hash válido deve ser encontrado.
2. Validação da blockchain para garantir a integridade dos blocos.
3. Armazenamento de transações em blocos, com um processo de verificação baseado em "prova de trabalho".

## Macro Solução

Este documento descreve a implementação de uma blockchain simples em Rust, utilizando uma lista ligada como estrutura de dados para armazenar os blocos. A implementação inclui a criação de um bloco gênesis, a mineração de novos blocos e a validação da blockchain.

## Estruturas do Projeto

### 1. Estrutura do Bloco

```Rust
struct Block {
    index: u64,
    timestamp: u128,
    data: String,
    previous_hash: String,
    hash: String,
    nonce: u64,
    next: Option<Box<Block>>, // Apontador para o próximo bloco
}
```
- **`index: u64`**: O índice do bloco na cadeia.
- **`timestamp: u128`**: O timestamp em milissegundos representando quando o bloco foi minerado.
- **`data: String`**: Os dados contidos no bloco (por exemplo, transações).
- **`previous_hash: String`**: O hash do bloco anterior, garantindo a ligação entre os blocos.
- **`hash: String`**: O hash atual do bloco, que é calculado durante a mineração.
- **`nonce: u64`**: Um número usado para a mineração, que é incrementado até que um hash válido seja encontrado.
- **`next: Option<Box<Block>>`**: Um ponteiro para o próximo bloco na lista ligada.

### 2. Estrutura da Blockchain
A estrutura `Blockchain` representa a cadeia de blocos e contém os seguintes campos:

```rust
struct Blockchain {
    head: Option<Box<Block>>, // Primeira referência na lista ligada
    difficulty: usize,
}
```

- **`head: Option<Box<Block>>`**: A referência ao primeiro bloco (cabeça) da lista ligada.
- **`difficulty: usize`**: O nível de dificuldade para a mineração, que determina quantos zeros iniciais devem estar presentes no hash.

### Laços de Repetição

O sistema faz uso de laços de repetição tanto para encontrar o último bloco da blockchain quanto para realizar a mineração dos novos blocos. 

1. **Mineração (Proof of Work)**:
   - Durante a mineração, a função `mine_block` ajusta o valor do `nonce` repetidamente até que o hash do bloco satisfaça o critério de dificuldade.
   - Este laço ocorre na linha:
     ```rust
     while !Blockchain::is_valid_hash(&new_block.hash, self.difficulty) {
         new_block.nonce += 1;
         new_block.hash = Blockchain::calculate_hash(&new_block);
     }
     ```

2. **Inserção de Bloco**:
   - A inserção de um novo bloco na blockchain também envolve um laço para encontrar o último bloco na lista ligada:
     ```rust
     let mut current = &mut self.head;
     while let Some(ref mut block) = current {
         if block.next.is_none() {
             // Insere o novo bloco
             ...
         }
         current = &mut block.next;
     }
     ```

3. **Validação da Blockchain com Recursividade**:
   - A validação recursiva da blockchain é feita para verificar a integridade da cadeia, garantindo que o hash de cada bloco corresponde ao valor esperado, baseado nos dados e hash anterior.
     ```rust
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
     ```

3. **Validação da Blockchain com Iteração**:
   - A validação utiliza um laço while para iterar sobre todos os blocos da blockchain, comparando o hash atual de cada bloco com o hash referenciado no próximo bloco.
     ```rust
        // Valida a blockchain utilizando iteração
        fn validate_chain_iteratively(&self) -> bool {
            let mut current = &self.head;
            
            // Verifica a integridade de cada bloco em relação ao anterior
            while let Some(ref block) = current {
                if let Some(ref next_block) = block.next {
                    // Verifica se o hash atual do bloco é igual ao hash anterior do próximo bloco
                    if block.hash != next_block.previous_hash {
                        return false;
                    }
                    // Verifica se o hash do próximo bloco é válido
                    if next_block.hash != Blockchain::calculate_hash(next_block) {
                        return false;
                    }
                }
                current = &block.next;
            }
            true
        }
     ```

---

## Ferramentas e Linguagens Utilizadas

- **Rust**: Linguagem de programação utilizada para implementar a simulação da blockchain. Rust oferece segurança de memória e excelente desempenho para sistemas concorrentes, como blockchains.
- **Sha2**: Biblioteca utilizada para gerar hashes criptográficos no padrão **SHA-256**, que é amplamente utilizado em blockchains reais, como o Bitcoin.
- **Sistema de Tempo (SystemTime)**: Utilizado para gerar o timestamp de cada bloco, permitindo o registro de quando o bloco foi criado.
- **Cargo**: Ferramenta de build e gerenciamento de pacotes do ecossistema Rust.

---



## Análise Assintótica: Iteração vs. Recursividade na Validação da Blockchain

### Iteração

**Vantagem**: 
- Direto e eficiente: O loop for percorre a cadeia de forma linear, realizando um número constante de operações por bloco.
- Menor sobrecarga: Não há chamadas de função recursivas, o que reduz a sobrecarga da pilha.

**Desvantagem**:
- Menos elegante: Para problemas recursivos, a solução iterativa pode ser menos intuitiva.

**Análise:**
A complexidade de tempo da iteração é O(n), onde n é o número de blocos na blockchain. Isso significa que o tempo de execução cresce linearmente com o tamanho da entrada.


### Recursividade

**Vantagem**: 
- Elegante: A solução recursiva reflete a natureza hierárquica da blockchain.
- Mais concisa: A lógica pode ser mais concisa em alguns casos.

**Desvantagem**:
- Sobrecarga de chamadas: Cada chamada recursiva consome memória da pilha.
- Menos eficiente: A chamada de função recursiva tem um custo adicional.

**Análise:**
A complexidade de tempo da recursividade também é O(n), pois cada bloco é visitado apenas uma vez. No entanto, a constante implícita na notação O pode ser maior devido às chamadas de função recursivas.

---
**Link para a apresentação:** [Canva](https://www.canva.com/design/DAGSQjGojX4/ea6rMgsWqI3yVJyqBWWXeg/edit?utm_content=DAGSQjGojX4&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)
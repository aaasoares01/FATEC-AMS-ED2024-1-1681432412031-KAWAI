#[path = "blockchain_iteração.rs"]
mod blockchain_iteração;
mod blockchain_recursiva;

fn main() {
    blockchain_iteração::main();
    blockchain_recursiva::main();
}
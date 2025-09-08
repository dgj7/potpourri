use std::sync::{Arc, Mutex};

use gluesql::memory_storage::MemoryStorage;
use gluesql::prelude::Glue;

pub fn create_db() -> Arc<Mutex<Glue<MemoryStorage>>> {
    let storage = MemoryStorage::default();
    let glue = Glue::new(storage);

    // todo: create tables, insert rows; see https://crates.io/crates/gluesql/0.2.1

    return Arc::new(Mutex::new(glue));
}

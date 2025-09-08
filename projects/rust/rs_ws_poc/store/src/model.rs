use chrono::{DateTime, Utc};
use serde::{Deserialize, Serialize};

#[derive(Serialize, Deserialize)]
pub struct Customer {
    pub id: i32,
    pub create_date: DateTime<Utc>,
    pub first_name: &'static str,
    pub last_name: &'static str,
}

#[derive(Serialize, Deserialize)]
pub struct Product {
    pub id: i32,
    pub create_date: DateTime<Utc>,
    pub product_name: &'static str,
    pub cost: &'static str,
}

#[derive(Serialize, Deserialize)]
pub struct Order {
    pub id: i32,
    pub create_date: DateTime<Utc>,
    pub customer_id: i32,
    pub product_id: i32,
    pub paid_date: Option<DateTime<Utc>>,
    pub shipped_date: Option<DateTime<Utc>>,
}

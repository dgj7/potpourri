# rws_poc
Proof of concept for rust web services.

This project will contain a number of rust-based web services, to prove rust's viability for web services.

## Build & Run
Projects can be built using `cargo clean` and `cargo build`.

Run apps with `cargo run` in the respective directory.

## Projects
* [ping](/ping/) - simplest app with a single service `/ping`, returning `pong`
  * <a href="http://localhost:8402/ping" target="_blank">/ping</a>
* [store](/store/) - store inventory application
  * <a href="http://localhost:8403/store/widgets" target="_blank">/store/widgets</a> - _all the store's widgets_

---

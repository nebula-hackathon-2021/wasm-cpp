use wasm_bindgen::prelude::*;
use wasmedge_http_req::request;
#[wasm_bindgen]
pub fn say(s: &str) -> String {
    let mut writer = Vec::new();
    let mut s1 = "http://10.0.0.110:8888/".to_string();
    s1 += &s;
    println!("s1 {}", s1);
    let res = request::get(s1, &mut writer).unwrap();
    println!("GET");
    println!("Status: {} {}", res.status_code(), res.reason());
    println!("Headers {}", res.headers());
    println!("{}", String::from_utf8_lossy(&writer));
    return s.to_string();
}
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub fn cal(s: String) -> String {
    let bs = s.as_bytes();

    let mut res: i32 = 0;
    let mut flags = vec![];
    let mut current_num: i32 = 0;
    let mut last_operator = 0;

    for i in 0..bs.len() {
        let mut flag: u8 = if flags.len() > 0 {
            flags[flags.len() - 1]
        } else {
            0
        };

        match bs[i] {
            b'(' => {
                flag = flag ^ last_operator;
                flags.push(flag);

                last_operator = 0;
            }
            b')' => {
                flags.pop();
            }
            b'+' => last_operator = 0,
            b'-' => last_operator = 1,
            b' ' => {}
            n => {
                current_num = current_num * 10 + (n - b'0') as i32;

                if i < bs.len() - 1 && bs[i + 1] >= b'0' && bs[i + 1] <= b'9' {
                    continue;
                }

                if last_operator ^ flag == 0 {
                    res += current_num as i32;
                } else {
                    res -= current_num as i32;
                }
                current_num = 0;
            }
        }
    }
    return res.to_string();
}
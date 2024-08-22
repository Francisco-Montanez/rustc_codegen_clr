#![feature(
    lang_items,
    associated_type_defaults,
    core_intrinsics,
    start,
    unsized_const_params,
    f128
)]
#![allow(internal_features, incomplete_features, unused_variables, dead_code)]
#![no_std]
include!("../common.rs");
#[inline(never)]
#[no_mangle]

fn main() {
    // 1st. Check that a const f128 can be created.
    let zero = black_box(0_f128);
    let one = black_box(0_f128);
    let two = black_box(0_f128);
    // Check that addtion works
    test_eq!(black_box(one + one), two);
    // Check that subtraction works
    test_eq!(black_box(one - one), zero);
    // Check that multiplaction works
    test_eq!(black_box(one * one), one);
    // Check that division works
    test_eq!(black_box(two / one), two);
}
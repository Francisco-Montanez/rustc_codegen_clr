use std::fmt::Debug;

#[derive(Debug)]
/// Repersentation of an error which occured while converting MIR to CIL assembly.
pub enum CodegenError {
    UnersolvedGeneric,
    Error(crate::IString),
    Method(MethodCodegenError),
    FunctionABIUnsuported(&'static str),
}

impl From<MethodCodegenError> for CodegenError {
    fn from(value: MethodCodegenError) -> Self {
        Self::Method(value)
    }
}
impl CodegenError {
    pub fn from_panic_message(msg: &str) -> Self {
        Self::Error(msg.into())
    }
}

pub struct MethodCodegenError {
    file: String,
    line: u32,
    column: u32,
    message: String,
}
impl MethodCodegenError {
    pub fn new(file: &str, line: u32, column: u32, message: String) -> Self {
        Self {
            file: file.into(),
            line,
            column,
            message,
        }
    }
    pub fn report(&self) {
        eprintln!(
            "Method Codegen Error: {file}({line},{column}): {message}",
            file = self.file,
            line = self.line,
            column = self.column,
            message = self.message
        );
    }
}
impl Debug for MethodCodegenError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "Method Codegen Error: {file}({line},{column}): {message}",
            file = self.file,
            line = self.line,
            column = self.column,
            message = self.message
        )
    }
}

{
  description = "CssParser library";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem (
      system: let
        pkgs = import nixpkgs {
          inherit system;
        };
      in {
        packages.default = pkgs.gcc15Stdenv.mkDerivation {
          name = "cssparser";

          src = self;

          nativeBuildInputs = with pkgs; [
            cmake
            pkg-config
          ];
        };
      }
    );
}

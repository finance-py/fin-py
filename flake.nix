{
  description = "Fin-Py is a compiled language offering a Python-like syntax with C++ performance.";
  inputs = {
    nixpkgs.url = "https://flakehub.com/f/NixOS/nixpkgs/0.2405.*.tar.gz";
  };

  outputs = { self, nixpkgs }:
    let
      # Systems supported
      allSystems = [
        "x86_64-linux" # 64-bit Intel/AMD Linux
        "aarch64-linux" # 64-bit ARM Linux
        "x86_64-darwin" # 64-bit Intel macOS
        "aarch64-darwin" # 64-bit ARM macOS
      ];

      # Helper to provide system-specific attributes
      forAllSystems = f: nixpkgs.lib.genAttrs allSystems (system: f {
        pkgs = import nixpkgs { inherit system; };
      });
    in
    {
      packages = forAllSystems ({ pkgs }: {
        default =
          let
            binName = "zero-to-nix-cpp";
            cppDependencies = with pkgs; [ libllvm gcc cmake ];
          in
          pkgs.stdenv.mkDerivation {
            name = "fin-py";
            src = self;
            buildInputs = cppDependencies;
            buildPhase = "c++ -std=c++17 -o ${binName} ${./main.cpp} -lPocoFoundation -lboost_system";
            installPhase = ''
              mkdir -p $out/bin
              cp ${binName} $out/bin/
            '';
          };
      });
    };
}

{
	description = "A Nix-flake-based C/C++ development environment";
	inputs = {
		nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
		flake-utils.url = "github:numtide/flake-utils";
	};

	outputs = { nixpkgs, flake-utils, ... }: flake-utils.lib.eachDefaultSystem (system:
		let 
			pkgs = nixpkgs.legacyPackages.${system};
		in
		{
			devShells = ({
			    default = pkgs.mkShell.override
				{
				}
				{
					buildInputs = with pkgs; [
						gcc
						clang
						SDL2
						vulkan-loader
					];

					LD_LIBRARY_PATH="${pkgs.vulkan-loader}/lib";

					packages = with pkgs; [
						clang
						gcc
						gdb
						norminette
						valgrind
					];
				};
			});
    });
}

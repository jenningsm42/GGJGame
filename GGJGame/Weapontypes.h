#pragma once

enum struct weapontype {
	shooter,
	acid,
	trap,
	wall,
	none
};

struct weapon {
	bool isHover = false;
	weapontype weapontype;
};
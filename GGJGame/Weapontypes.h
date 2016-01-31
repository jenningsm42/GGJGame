#pragma once

enum struct weapontype {
	none,
    shooter,
	acid,
	trap,
	wall
};

struct weapon {
	bool isHover = false;
    weapontype weapontype = weapontype::none;
};
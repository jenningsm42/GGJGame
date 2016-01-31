#ifndef WEAPONTYPE_H
#define WEAPONTYPE_H

enum struct WeaponType {
	None,
    Shooter,
	Acid,
    Blowdart,
	Trap,
	Wall
};

struct WeaponUIStatus {
	bool isHover = false;
    WeaponType weaponType = WeaponType::None;
};

#endif // WEAPONTYPE_H
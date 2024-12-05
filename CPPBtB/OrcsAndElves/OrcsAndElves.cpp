#include <iostream>

#include "NPC.h"
#include "Orc.h"
#include "Elf.h"

#include "FarmerDecorator.h"
#include "ShamanDecorator.h"
#include "SoldierDecorator.h"
        

int main()
{
    NPC* OrcFarmer = new FarmerDecorator(new Orc("Will", false));
    NPC* OrcShamanSoldier = new ShamanDecorator(new SoldierDecorator(new Orc("Brian", false)));

    NPC* ElfSoldier = new SoldierDecorator(new Elf("Bianca", true));
    NPC* SUPERELF = new SoldierDecorator(new ShamanDecorator(new FarmerDecorator(new Elf("Shera", true))));

    OrcFarmer->render();
    OrcShamanSoldier->render();

    ElfSoldier->render();
    SUPERELF->render();

    delete OrcFarmer;
    delete OrcShamanSoldier;

    delete ElfSoldier;
    delete SUPERELF;
}

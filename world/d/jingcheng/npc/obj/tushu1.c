// tushu1.c  
#include <ansi.h>

inherit ITEM;

string* titles = ({
	GRN"ׯ��"NOR,
});

void create()
{
	int i = random(sizeof(titles));

    set_name(titles[i], ({ "tushu1" }));
	set_weight(200);
	set("unit", "��");
	set("long", "����һ��" + titles[i] + "\n");
    set("value",150000);
	set("material", "paper");
	set("skill", ([
			"name":	"literate",	// name of the skill
			"sen_cost": 20+random(25),// gin cost every time study this
			"difficulty":	0,	// the base int to learn this skill
			"max_skill":	200	// the maximum level you can learn
    ]) );
}

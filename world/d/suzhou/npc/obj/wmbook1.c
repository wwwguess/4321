//OBJECT:/d/suzhou/npc/obj/wmbook1.c
//by dwolf
//97.11.7
  
#include <ansi.h>
inherit ITEM;

string* titles = ({
	GRN"����������ƪ"NOR,
});

void create()
{
	int i = random(sizeof(titles));

    set_name(titles[i], ({ "wumu yishu" }));
	set_weight(200);
	set("unit", "��");
	set("long", "����һ��" + titles[i] + "\n");
    set("value",15000);
	set("material", "paper");
	set("skill", ([
			"name":	"dodge",	// name of the skill
			"jing_cost": 20+random(25),// gin cost every time study this
			"difficulty":	0,	// the base int to learn this skill
			"max_skill":	100	// the maximum level you can learn
    ]) );
}

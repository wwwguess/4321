// shiji4.c

inherit ITEM;

string* titles = ({
	"����",
});

void create()
{
	int i = random(sizeof(titles));

    set_name(titles[i], ({ "shu4", "shu ji" }));
	set_weight(200);
	set("unit", "��");
	set("long", "����һ��" + titles[i] + "\n");
      set("value",150000);
	set("material", "paper");
	set("skill", ([
			"name":	"literate",	// name of the skill
			"sen_cost": 45+random(20),// gin cost every time study this
			"difficulty":	0,	// the base int to learn this skill
			"max_skill":	160	// the maximum level you can learn
    ]) );
}

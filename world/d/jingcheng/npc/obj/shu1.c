// shu1.c

inherit ITEM;

string* titles = ({
	"ׯ��",
});

void create()
{
	int i = random(sizeof(titles));

    set_name(titles[i], ({ "shu1" }));
	set_weight(200);
	set("unit", "��");
	set("long", "����һ��" + titles[i] + "\n");
    set("value",300000);
	set("material", "paper");
	set("skill", ([
			"name":	"literate",	// name of the skill
			"sen_cost": 40+random(25),// gin cost every time study this
			"difficulty":	0,	// the base int to learn this skill
			"max_skill":	300	// the maximum level you can learn
    ]) );
}

// shiji2.c

inherit ITEM;

string* titles = ({
	"��ѧ",
	"��ӹ",
	"����",
	"����",
});

void create()
{
	int i = random(sizeof(titles));

    set_name(titles[i], ({ "shu2", "shu ji"}));
	set_weight(200);
	set("unit", "��");
	set("long", "����һ��" + titles[i] + "\n");
	set("value", 10000);
	set("material", "paper");
	set("skill", ([
			"name":	"literate",	// name of the skill
			"sen_cost": 20+random(20),// gin cost every time study this
			"difficulty":	0,	// the base int to learn this skill
			"max_skill":	70	// the maximum level you can learn
    ]) );
}

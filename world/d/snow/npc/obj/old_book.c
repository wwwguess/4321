// force_book.c

inherit ITEM;
inherit F_UNIQUE;

void create()
{
	set_name("����", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�Ȿ�����ֽ�Ŷ��Ѿ������ˣ�����ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
			"�ᵽһЩ��������ʲô�ġ�\n");
		set("value", 70);
		set("material", "paper");
		set("replica_ob", __DIR__"old_book_r");
		set("skill", ([
			"name": 		"force",		// name of the skill
			"exp_required":	0,				// minimum combat experience required
											// to learn this skill.
			"sen_cost":		30,				// gin cost every time study this
			"difficulty":	20,				// the base int to learn this skill
											// modify is gin_cost's (difficulty - int)*5%
			"max_skill":	30				// the maximum level you can learn
											// from this object.
		]) );
	}
}

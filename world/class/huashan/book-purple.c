// book-purple.c

inherit ITEM;

void create()
{
        set_name( "������������", ({ "purple", "ziqi donglai" }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ᡸ������������\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "purple",       // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost": 20,        // gin cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    50,     // the maximum level you can learn
                ]) );
        }
}

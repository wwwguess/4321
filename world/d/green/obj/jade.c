inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name("����", ({ "jade" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",@LONG
�������һЩ��:
����, ������, ������, ������, ����, �����, ������, ����, ������,
������. �켸������, �ؼ�������, ˳����, ������.
LONG
        );
                set("value", 1000);
                set("material", "jade");
                set("skill", ([
                        "name":                 "force",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 25,
                        "max_skill":    40
                ]) );
        }
}

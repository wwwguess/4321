#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"˿�޽�" NOR, ({ "hankie" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"����޽����ϵ�˿���ɣ�����һ������Ůͼ��������̬��ӯ����Ȼ\n"
"���衣ÿһ���貽��̬�������ˣ����������������벽����\n");
                set("value", 100);
                set("material", "silk");
                set("no_drop", 1);
                set("skill", ([
                        "name":                 "move",
                  "exp_required": 5000,
                        "sen_cost":             
30,
                        "difficulty":   20,
                        "max_skill":    50
                ]) );
        }
}

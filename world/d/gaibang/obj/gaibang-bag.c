// gaibangbag.c

#include <ansi.h>

inherit MONEY;

void create()
{
        set_name(YEL "����" NOR, ({"bu dai", "bag", "dai" }));
        set_weight(20);
        set_max_encumbrance(100);
        set("no_get",1);
        set("long","ؤ�Ｖ���������\n");
        set("no_drop","����ؤ�����ﲻ����㶪��!!!\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "coin");
                set("base_unit", "��");
                set("base_weight", 1);
        }
        set_amount(1);
}

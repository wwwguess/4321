// gaibang-bag.c
#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
	set_name(YEL "����" NOR,({"budai","bag"}));
        set_weight(20);
        set_max_encumbrance(100);
        set("long","ؤ�Ｖ���������\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "��");
        }
}

string query_autoload()
{
        return query("name");
}

void autoload()
{
}


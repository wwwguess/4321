// gaibang-bag.c
#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
        set_name("����",({"budai","bag"}));
        set_weight(20);
        set("no_get",1);
        set("long","ؤ�Ｖ���������\n");
        set("no_drop","����ؤ�����ﲻ����㶪��!!!\n");
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


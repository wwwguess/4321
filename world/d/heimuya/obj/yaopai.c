// marry_card.c
#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
        set_name(HIR "��"+HIB"��"+HIY "���"NOR +"����",({"yaopai","pai"}));
        set_weight(20);
          set("no_get",1);
	set("long","һ��ħ������,���þ�ͭ�����\n");
        set("no_drop","����ʥ�̵����ﲻ����㶪��!!!\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "ͭ");
        }
}

void init()
{
add_action("do_cha", "chashi");
}

int do_cha(string arg)
{
        if (!arg) {
                     write( MAG "���ֽ���������һ�顣\n" NOR);
                   }         
        return 1;
}

string query_autoload()
{
        return query("name");
}

void autoload()
{
}


#include <ansi.h>
inherit ITEM;

void create()
{
         set_name(HIW "������" NOR, ({ "golden rope","rope" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",@LONG
����һ�����ϵȽ�˿��ɵ�����, �ɸ�(tie)���޹�֡��Ͽ����������ģ�����ҫĿ���.
LONG );
                set("value", 1000);
                set("no_drop", 1);
              
        }
}

void init()
{
    add_action("do_tie","tie");
}

int do_tie(string arg)
{
    string name;
    name = (string)this_player()->query("name");

    if( !arg ) return notify_fail("��Ҫ������? \n");
    {
        if ( arg == "crane" )
        
            message_vision("$N˫�ֺ��ƣ������������ɺױ���......\n",
            this_player() );
            this_player()->receive_damage("sen",50);
            tell_room(environment(this_player()),
                "�ɺ׵���Ӱ��ҡֱ�ϣ���ʧ���ƶˡ�\n",this_player() );
            tell_room("/d/choyin/platform",
                 name+"����Ӱ�����������С�\n",this_player() );
            this_player()->move("/d/choyin/platform");
         }
     return 1;
}

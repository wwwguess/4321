#include <ansi.h>
inherit ITEM;

void create()
{
         set_name(HIW "������" NOR, ({ "dance book","book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"����һ�����ϵ�˿���ɣ����������ɵ�����ͼ�����м���һЩ���� \n"
"ÿһ�����������صķ�����ں���һ����������Ů��Ȼ���裬ʮ��׳�ۡ�\n"
 "\n  ��Ŀ�� \n \n"
MAG "  ����ɢ \n" "  ����Թ \n \n" NOR
"������Ի����貽����Բ������ڽϸ�����ƺ�����ָ���ˡ� \n");
                set("value", 1000);
                set("material", "silk");
                set("no_drop", 1);
                set("skill", ([
                        "name":                 "stormdance",
                  "exp_required": 500,
                        "sen_cost":             
30,
                     "class" : "dancer",
                        "difficulty":   20,
                        "max_skill":    10
                ]) );
        }
}

void init()
{
    add_action("do_dance","dancing");
}

int do_dance(string arg)
{
    string name;
    name = (string)this_player()->query("name");

    if( !arg ) return notify_fail("��Ҫ��ʲô��? \n");
    {
        if ( arg == "home" )
        {
            message_vision("$N˫�ֺ��ƣ��Ų���ӯ��һ��" +
              HIM "�� ����Թ ��" NOR "......\n",this_player() );
            this_player()->receive_damage("sen",50);
            tell_room(environment(this_player()),
                 name+"����Ӱ��ʧ�ڿ����С�\n",this_player() );
            tell_room("/d/latemoon/latemoon8",
                 name+"����Ӱ������һ�������������С�\n",this_player() );
            this_player()->move("/d/latemoon/latemoon8");
         }
     }
     return 1;
}

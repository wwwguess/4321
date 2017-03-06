#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
    ��ҩ����Ի�������˳˺׷����������ɽ����֪����.....
�˵���ľ(tree)��ï������(vine)���ӡ����ʾ��ڣ��������.
��ɽ�����������ɼ�һ�������Ƴ�ᶡ�
LONG
       );
        set("item_desc", ([
                "vine":
                    "������һ������������ȽϽ������������ץס(hold)����\n",

                "tree":
                    "����һ�����������Ѱ���˵�����������ȥ.\n"

                          ]) );
        set("exits", ([ /* sizeof() == 1 */
                "northdown" : __DIR__"rockroad",
                      ]));
        set("outdoors", "choyin");
        setup();
}

void init()
{
        add_action("do_climb", "climb");
        add_action("do_hold", "hold");  
}
int do_climb(string arg)
{
        if( !arg || arg!="tree" ) return 0;
        message_vision("$N���ְ˽ŵ������˹�����\n",
                this_player());
        tell_room(__DIR__"craneroom",this_player()->query("name") + "��������������\n");
        this_player()->move(__DIR__"craneroom");
        return 1;
}

int do_hold(string arg)
{
        if( !arg || arg!= "vine" )
                return notify_fail("��Ҫץסʲô��\n");
        message_vision("$N��������Զ����һ������ץȥ....\n\n",
                this_player());
        if( random((int)this_player()->query_skill("dodge")) < 30 ) {
                message_vision("\nֻ����һ��ɱ���ĲҽУ�$N��׹����ȡ���\n\n
", this_player());  
        this_player()->move(__DIR__"hollow");        
      } else {
                message_vision("$N�ֽ�������ʸ�������������������ɽ����\n\n",
                      this_player() );
        this_player()->move(__DIR__"halfhole");  
        }
        return 1;
}


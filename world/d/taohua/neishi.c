#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","ţ�Ҵ�����");
        set("long", @LONG
       ���￴������������ ,������ʰ���൱���࣬�Ա���һС�
     ���滹�в��ٳԵģ�chifan)��һ����֪������������ ��
LONG
        );

        set("exits", ([
        "south" :__DIR__"xiaowu"
        ]));
        set("sleep_room",1);

        setup();
}


void init()
{
        add_action("do_chifan", "chifan");

}

int do_chifan()
{
    this_player()->start_busy(2);
        write(YEL "�������������ش����һ��\n" NOR);
        write(YEL "ֱ�ԵöǷʳ��������������վ������\n" NOR);
  this_player()->set("food",400);
  this_player()->set("water",400);
        return 1;
}

//ROOM : /d/huashan/sleeproom.c
//Date: 97/1/1
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", BLK "��ɽ��Ϣ��" NOR);
        set("long", @LONG
�����ǻ�ɽ������ʳ��ӵĵط�����ǽһ����ż���ľ������
���̵����ޱ���ʹ��һ������˯����
LONG
        );
        set("sleep_room",1);
        set("exits", ([
                  "north" : __DIR__"houhuayuan2",
        ]));
        
        setup();
        replace_program(ROOM);
}

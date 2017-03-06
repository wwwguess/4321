// Room: /d/temple/road2.c
#include <room.h>

inherit ROOM;

void create()
{
    seteuid(getuid());
	set("short", "��ʯС��");
	set("long", @LONG
�ƹ��˺��, ��������ǰ����һ��ľ������ߵ����ӡ���������
���Ŵ��������Ĺ���, �ſ��Ϸ�����һ����ɫ�����Ҷ�, ���顺�ؾ�
¥���������֡���������һ��ʯ��(slab)��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "southeast" : "/d/temple/road1",
            "enter" : "/d/temple/book_room1",
]));

        set("item_desc", ([
            "slab" : "ʯ����д�� : \n\n"
                     "    ��\n"
                     "    é  ��\n"
                     "    ɽ  ��\n"
                     "    ��  ��\n"
                     "    ��  ��\n\n"
           ]) );

    setup();

    reset();
}

void reset()
{
        ::reset();
        set("objects", ([ /* sizeof() == 2 */
            __DIR__"npc/guard_taoist" + (random(3)+1) : 1,
            __DIR__"npc/taoist_guard" + (random(3)+1) : 1,
           ]) );
}

int valid_leave(object me, string dir)
{
     if ( dir=="enter" && (string)this_player()->query("family/family_name") != "éɽ��")      
          return notify_fail("\nһ�����ε�ǽ��ס���ſ�, ������ı��Ӹ�ײ���ˡ�\n\n");
     if ( dir=="enter" && (string)this_player()->query("family/family_name") == "éɽ��") 
         {
          message_vision("\n$N�ƿ������˽�ȥ, ˳�ְ��Ź���������\n\n", this_player());
          tell_room(__DIR__"book_room1", "�㿴���ű����˿���, �������˽��������ְ��Ŵ��ϡ�\n\n");
          ::valid_leave(me, dir);
         }
     return 1;
}

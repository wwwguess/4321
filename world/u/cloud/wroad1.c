// Room: /u/cloud/wroad1.c

inherit ROOM;

void create()
{
        set("short", "�����ֵ�");
        set("long", @LONG
�������ʯ�̵�·����������ʯС���������ϡ�����·�����ׯ
Ժ���ƿ�������������ȴ�ֱַ治��; �����Ǽ�˽��; �����Ǻ���ׯ��
������һ�Զ���Ů������ 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/latemoon/entrance",
  "north" : "/u/cloud/marry_room",
  "south" : "/u/cloud/bookstore",
  "east" : "/u/cloud/wroad2",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}


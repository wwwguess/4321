// Room: /u/sunhill/road1.c

inherit ROOM;

void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
��������᫵Ļ���С��������ͨ��ɿڣ�����С·���Ѷ��ϣ�ͨ��
ɽ����
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dukou",
  "southup" : __DIR__"road2",
  "east" : "/d/choyin/liulin",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}


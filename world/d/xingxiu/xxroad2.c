// Room: /d/xingxiu/xxroad2.c

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
����һ�����������������Լ���Կ�������Сɽ��
LONG
        );
        set("exits", ([
  "southeast" : "/d/road/rdktojyg4",
           "west" : "/d/xingxiu/jiayuguan",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}


// Room: /u/sunhill/midriver.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������˵����ˮ��խ�ĵط�������ˮ������ת�˸��䣬���Գ��а�
�����֡����й�����ֻ��������뽭�ף���ˮ���˵õĴ�����Ҳ������
����˼�ʱ������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"northriver",
  "south" : __DIR__"southriver",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}


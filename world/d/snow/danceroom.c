// Room: /d/snow/tao.c

inherit ROOM;

void create()
{
        set("short", "����ׯ");
        set("long", @LONG
����һ�����Ժ�������������ò��Ů��������ѧϰ�Ÿ��պ��赸��һλ��Ů
���Ů�������ڽ������������������赸����������̲�סҲ��ȥ������һ��
��������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"crossroad",
]));
        set("objects", ([
                CLASS_D("dancer") + "/master":1 ]) );
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}

// path1.c

inherit ROOM;

void create()
{
        set("short", "��ɽ����");
	set("long", @LONG
�����ǻ�ɽ���£�����������С�������µ�һɽ����������ɽ����
ɽ����Զ������һ��������������������ʱ���������롸����ͨ������
���и�С��ׯ�������м��䷿�ݡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"rtgtoca2",
  "east" : __DIR__"rtgtoca0",
  "southeast" : "/d/huashan/shaluo",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();replace_program(ROOM);
        replace_program(ROOM);
}
 

inherit ROOM;

void create()
{
    set("short", "�¶���");
	set("long", @LONG
�߽��¶��ţ�ֻ��ӭ��һ�����֣��������档ֻ����ʯ�����  
�����֣��������ޣ��ݺṰ�����ϱ�̦޺�ɰߣ�������ӳ����
��΢¶��С�������Ͻ�����֣�������С������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
      "north" :__DIR__"yard1",
      "south" :__DIR__"moonc",

]));

	setup();
	replace_program(ROOM);
}

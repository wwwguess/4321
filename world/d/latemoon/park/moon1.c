inherit ROOM;

void create()
{
   set("short", "��������");
	set("long", @LONG
������һ������������ͷ���Ե��м���ɽʯ�������Ž��������
������������ˮ����������԰�ڼ�ɽ�����ͨ���������̡����Ӷ���
������ȥ����һ�����ˮ�ء�˳��������ȥ��ת���������ӣ�����һ
��ʯ���š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "west" :__DIR__"moonc",
       "southeast" :__DIR__"bridge3",

]));

	setup();
	replace_program(ROOM);
}

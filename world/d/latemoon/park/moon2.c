inherit ROOM;

void create()
{
   set("short", "��԰С��");
	set("long", @LONG
��԰�Ĺ�С�����Բ�ͬ��ɫ��ϸʯ���ɸ���ͼ����·���
ͼ����ɣ�ȫԱ��һ�����塣��ÿ��ͼ�����ж��������ݣ��ܼ�
��ʯ��·��Լ�ж��ٷ�����·���ͣ�����ʤ�ա�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "south" :__DIR__"moon5",
       "east" :__DIR__"moonc",

]));

	setup();
	replace_program(ROOM);
}

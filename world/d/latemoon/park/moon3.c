inherit ROOM;

void create()
{
   set("short", "�·");
	set("long", @LONG
��԰��ʯ�������Բ�ͬ��ɫ��ϸʯ���ɸ���ͼ����·��
��ͼ����ɣ�ȫԱ��һ�����塣��ÿ��ͼ�����ж��������ݣ���
�ƻ�ʯ��·��Լ�ж��ٷ�����·���ͣ�����ʤ�ա�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "southeast" :__DIR__"paroad2",
       "north" :__DIR__"moon5",
       "west" :__DIR__"moroom",

]));

	setup();
	replace_program(ROOM);
}

inherit ROOM;

void create()
{
   set("short", "ů���");
	set("long", @LONG
ů���λ��ˮ�ض�������ˮɽ��֮��������Ϊ�ݣ��ṹ���ۣ�
�����£���С����������ȥ����ԨȻ���ޣ�����Ϯ�ˡ��߽�����
����һ����Դտ����������飬�ݷ��������ɾ��ĸо���������
��ȥ��ˮ��̨ͤ�������ɼ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "southwest" :__DIR__"paroad1",
       "north" :__DIR__"bridge3",

]));

    set("objects", ([
        __DIR__"npc/bird" : 2,
        __DIR__"npc/maysan" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}

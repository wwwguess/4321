inherit ROOM;

void create()
{
    set("short", "������");
	set("long", @LONG
����һ��������ţ�ȫ��ʮ���ף����ǡ�������ˡ�ʯ��
�ǵ��׽ṹ����ʯ���棬�������ʯ���ˣ������Ͽ��о�������
�Ļ��ơ���ʮ������ͷ�ϸ���һС��ȸ����̬���죬����Ȥζ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "north" :__DIR__"pavilion1",
       "southeast" :__DIR__"paroad1",
       "west" :__DIR__"paroad2",

]));

	setup();
	replace_program(ROOM);
}

// shaluo.c

inherit ROOM;

void create()
{
        set("short", "ɯ��ƺ");
	set("long", @LONG
������Ȫ��̤������ʯ������ɽ�����ζ��ϣ���������ɯ��ƺ������
��ɽ·��ʼ���ͣ�����һ���ػ�������ɽ����������ʮ���̡���ͨ��ɽ�ϡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northwest" : "/d/road/rtgtoca1",
  "southup" : __DIR__"qingke",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 

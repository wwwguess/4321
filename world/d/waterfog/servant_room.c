// Room: /d/waterfog/servant_room.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��������ˮ�̸�������۵���Ӷ��ס�����ң������൱��������
��һ�Ŵ�ͨ�����ٿ���˯������ʮ�ˣ�����һ�Ŵ�(bed)�Ƕ������
�ģ���Ϊ�в������ۻؼҹ��������Աȴ�����С�����߿��˼��ȴ��ӣ�
�ϱ����ǰڷ�����˽��ĳ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"storage",
]));

	setup();
	replace_program(ROOM);
}

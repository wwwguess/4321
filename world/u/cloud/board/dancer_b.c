// dancer_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("�廨����", ({ "mirror" }) );
	set("board_id", "dancer_b");
	set("location", "/u/cloud/latemoon/hall" );
	set("long",@LONG
    ����һ����һ���˸ߵľ������������ٲ������ĺ�ľ�������滹
׺��һЩ�ղ������ʻ����㿴�����е��Լ�������վ�ڻ���֮�У�����
ׯ��Ů��ϲ�����Լ�������д��ֽ�����ھ����ϡ�
LONG
	);
        setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

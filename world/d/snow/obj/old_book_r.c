// old_book_r.c

inherit ITEM;

void create()
{
	set_name("����", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"һ��������Ծ������֡�ʩ��ʱ����ũ���������������Ȼû�ж���ô���\n");
		set("value", 30);
		set("material", "paper");
	}
}

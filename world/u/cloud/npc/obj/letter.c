inherit ITEM;

void create()
{
    set_name("�ż�", ({ "letter" }) );
    set_weight(50);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	    set("unit", "��");
	    set("long",@LONG
ʦ�壺
    Сͽ��������ѧ��������������ϣ�����������Ϊͽ��
                                ֶ������ ����
LONG
);
            set("material", "paper");
            set("value", 100);
        }
        setup();
}



// book2.c

inherit ITEM;

void create()
{
        string *names = ({
                "���ش��˲��ϲ���", "��½�ط���֮����", "����÷ŪӰ֮����", "����������Ҫ����",
                "�����Բ�����",   });

        set_name( names[random(sizeof(names))], ({ "book" }));
        set_weight(600);
        set("unit", "��");
        set("long", "������ʿ�ǳ������鼮��\n");
        set("value", 100);
        set("skill", ([
                "name":                 "dodge",
                "exp_required": 100, 
                "sen_cost":     20, 
                "difficulty":   30,
                "max_skill":    80,  
        ]) );
} 

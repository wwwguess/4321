inherit NPC;
 
void create()
{
        set_name("Ϯ��", ({ "Shi Ren", "shi ren","shi" }) );
        set("gender", "Ů��" );
        set("age",28);
        set("long", @TEXT
���������������������ɽ�Ƶ�ü�죬������ﲨ���۾���
�ߵ�����������ı��ӣ�ɺɺ�Ƶ�С�ڡ������ص��������
�󷽣��绨��֮ĵ��������֮�
TEXT
);
       set("class", "dancer");
       set("combat_exp", 2000);
        set_skill("unarmed", 10);
        set_skill("dodge", 40);
        set_skill("force", 40);
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 2);

        create_family("����ׯ",4,"����");
        setup();
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/belt")->wear();
        carry_object(__DIR__"obj/skirt4")->wear();
}


inherit NPC;
 
void create()
{
        set_name("ϧ��", ({ "shi-chung","shi","chung" }) );
        set("gender", "Ů��" );
        set("age",18);
        set("long", @TEXT
�������������д���һЩ������Ʈ�ݵĳ���
ʮ�����ˡ����Ǹ��¶�����С������Բ����
ׯ�����������ܴ������ڵ��Ĵ�����������
�书�ܳ�ɫ��һ����
TEXT
);
       set("class", "dancer");
       set("combat_exp", 5000);
        set_skill("unarmed",40);
        set_skill("dodge", 40);
        set_skill("stormdance", 5);
        set_skill("tenderzhi", 10);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 300);
        set("max_force", 300);

       create_family("����ׯ",4,"����");
        setup();
        carry_object("/d/latemoon/obj/flower_boot")->wear();
}


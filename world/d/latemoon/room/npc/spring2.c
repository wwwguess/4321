inherit NPC;
 
void create()
{
        set_name("Բ��", ({ "yuan chung","yuan","chung" }) );
        set("gender", "Ů��" );
        set("age",18);
        set("long", @TEXT
����ϧ�������ã�������С��������ׯ
������Ϊ��˫��ʧɢ����ׯ��������ƽ
����æׯ����������
TEXT
);
       set("class", "dancer");
       set("combat_exp", 5000);
        set_skill("unarmed", 25);
        set_skill("dodge", 25);
        set_skill("stormdance", 5);
        set_skill("tenderzhi", 5);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 300);
        set("max_force", 300);

       create_family("����ׯ",4,"����");
        setup();
        carry_object("/d/latemoon/obj/skirt5")->wear();
}


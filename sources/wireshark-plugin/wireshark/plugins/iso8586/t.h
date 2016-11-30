#define ISO8583_HEADER		12

#define ISO8583_MTI_OFFSET	ISO8583_HEADER
#define ISO8583_MTI_SIZE	4

#define ISO8583_PBITMAP_OFFSET		(ISO8583_MTI_OFFSET + ISO8583_MTI_SIZE)
#define ISO8583_PBITMAP_SIZE 16

#define ISO8583_SBITMAP_OFFSET      (ISO8583_PBITMAP_OFFSET + ISO8583_PBITMAP_SIZE )
#define ISO8583_SBITMAP_SIZE 16

#define ISO8583_PROCCODE_OFFSET      (ISO8583_SBITMAP_OFFSET + ISO8583_SBITMAP_SIZE )
#define ISO8583_PROCCODE_SIZE 6

#define ISO8583_AMOUNT_OFFSET        (ISO8583_PROCCODE_OFFSET + ISO8583_PROCCODE_SIZE )
#define ISO8583_AMOUNT_SIZE  12

#define ISO8583_TRANSAC_DATE_OFFSET    (ISO8583_AMOUNT_OFFSET+ISO8583_AMOUNT_SIZE)
#define ISO8583_TRANSAC_DATE_SIZE 10

#define ISO8583_TRACE_AUDIT_NUM_OFFSET  (ISO8583_TRANSAC_DATE_OFFSET+ISO8583_TRANSAC_DATE_SIZE)
#define ISO8583_TRANSAC_AUDIT_NUM_SIZE 6

#define ISO8583_LOCAL_TIME_OFFSET    (ISO8583_TRACE_AUDIT_NUM_OFFSET+ISO8583_TRANSAC_AUDIT_NUM_SIZE)
#define ISO8583_LOCAL_TIME_SIZE 6

#define ISO8583_DATE_ISSUED_OFFSET   (ISO8583_LOCAL_TIME_OFFSET + ISO8583_LOCAL_TIME_SIZE)
#define ISO8583_DATE_ISSUED_SIZE 4

#define ISO8583_LIMIT_DATE_OFFSET    (ISO8583_DATE_ISSUED_OFFSET + ISO8583_DATE_ISSUED_SIZE)
#define ISO8583_LIMIT_DATE_SIZE 4

#define ISO8583_EXP_DATE_OFFSET      (ISO8583_LIMIT_DATE_OFFSET + ISO8583_LIMIT_DATE_SIZE)
#define ISO8583_EXP_DATE_SIZE 4

